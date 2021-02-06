<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>관리자용 데이터 조회</title></head>
<body>
<div align="center"> 
<%
request.setCharacterEncoding("UTF-8"); 
String id = (String)session.getAttribute("id"); 
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger"; 
String sql =  "select * from bankmember"; 
String sql2 =  "select * from banktrade order by tradedate desc"; 
String sql3 = "select * from bankmember_tal";
try{ 
Class.forName("oracle.jdbc.driver.OracleDriver"); 
Connection conn = DriverManager.getConnection(url, uid, pass); 
PreparedStatement pre = conn.prepareStatement(sql); 
ResultSet rs = pre.executeQuery(); 
%> 
<h2>관리자용 데이터 조회</h2>
 
 
<h4> 회원 리스트 </h4> 
<table width="500" border="1"> 
<tr>
<th>아이디</th> <th>비밀번호</th> <th>이름</th> <th>나이</th> <th>휴대폰번호</th> <th>잔액</th>
</tr> 
<%
while(rs.next()) {%>
<tr>
<td><%=rs.getString("id")%></td> <td><%=rs.getString("pw")%></td> <td><%=rs.getString("name")%></td> <td><%=rs.getInt("age")%></td> <td><%=rs.getString("phone")%></td> <td><%=rs.getInt("balance") %></td>
</tr> 
<% } %> 
</table> 
 
<%
pre = conn.prepareStatement(sql3); 
rs = pre.executeQuery(); 
%>
<p><p><p>
 
<h4> 탈퇴 회원 리스트 </h4> 
<table width="500" border="1"> 
<tr>
<th>아이디</th> <th>비밀번호</th> <th>이름</th> <th>나이</th> <th>휴대폰번호</th> <th>잔액</th>
</tr> 
<%
while(rs.next()) {%>
<tr>
<td><%=rs.getString("id")%></td> <td><%=rs.getString("pw")%></td> <td><%=rs.getString("name")%></td> <td><%=rs.getInt("age")%></td> <td><%=rs.getString("phone")%></td> <td><%=rs.getInt("balance") %></td>
</tr> 
<% } %> 
</table> 
 
 
<%
pre = conn.prepareStatement(sql2); 
rs = pre.executeQuery(); 
%>
<p><p><p>
 
<h4> 총 거래 내역 </h4> 
<table width="500" border="1"> 
<tr>
<th>거래일자(최근일순)</th> <th>입금액</th> <th>출금액</th> <th>이체여부</th> <th>이체상대</th>
</tr> 
<%
while(rs.next()) {%>
<tr>
<td><%=rs.getString("tradedate")%></td> <td><%=rs.getString("deposit")%></td> <td><%=rs.getString("withdraw")%></td> <td><%=rs.getInt("trans")==1?"이체보냄":rs.getInt("trans")==2?"이체받음":""%></td> <td><%=rs.getString("trade_id")%></td>
</tr> 
<% } %> 
</table> 
<p><p> 
<a href="BANK_menu.jsp" > 메뉴로 돌아가기 </a> <p> 
</div>
<% } catch (Exception e) { 
out.print("거래내역 조회 중 문제 발생.<p>" + e.getMessage()); 
}
%>
 
</body>
</html>