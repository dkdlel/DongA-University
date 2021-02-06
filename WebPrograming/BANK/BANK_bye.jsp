<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>회원 탈퇴</title></head>
<body>
<%
request.setCharacterEncoding("UTF-8"); 
String id = (String)session.getAttribute("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";
String sql =  "select balance from bankmember where id = ?"; 
 
try{ 
Class.forName("oracle.jdbc.driver.OracleDriver"); 
Connection conn = DriverManager.getConnection(url, uid, pass); 
PreparedStatement pre = conn.prepareStatement(sql);
pre.setString(1,id); 
ResultSet rs = pre.executeQuery(); 
rs.next();
int balance = rs.getInt("balance");
// 잔액 0원이 아니면
if(balance != 0){%>
<font color="blue"><%=id%></font>님의 잔액이 아직 <strong><%=balance %></strong>원 남아있습니다.<p>
<%}%>
<h3> 정말 회원탈퇴를 진행하시겠습니까? </h3><p><p>
<a href="BANK_menu.jsp" > 취소(메뉴로 돌아가기) </a> &nbsp; &nbsp;
<a href="BANK_secede_delete.jsp" > 회원 탈퇴 처리 즉시 진행 요청 </a> <p> 
 
 <%} 
catch (Exception e) { 
out.print("회원탈퇴 중 문제 발생 <p>" + e.getMessage()); 
}
%>
</body>
</html>