<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>잔액조회</title></head>
<body>
<%
request.setCharacterEncoding("UTF-8");
String id = (String)session.getAttribute("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select balance from bankmember where id = ?"; 
String sql2 = "select max(tradedate) from banktrade where id = ?";
try{ 
	Class.forName("oracle.jdbc.driver.OracleDriver"); 
	Connection conn = DriverManager.getConnection(url, uid, pass); 
	PreparedStatement pre = conn.prepareStatement(sql); 
	pre.setString(1,id); 
	ResultSet rs = pre.executeQuery(); 
	rs.next();
	out.print(id +"님의 잔액은" + rs.getInt("balance") + "원 입니다. <p><p>");
	PreparedStatement pre2 = conn.prepareStatement(sql2);
	pre2.setString(1,id);
	ResultSet rs2 = pre2.executeQuery();
	rs2.next(); 
	out.print("최근 거래일은 " + rs2.getString(1) + "입니다. <p><p>");
	%>
	<a href = "BANK_menu.jsp" > 메뉴로 돌아가기 </a> <p> 
<% } 
catch (Exception e) { 
	out.print("잔액조회 중 문제 발생 <p>" + e.getMessage()); 
}
%>

</body>
</html>