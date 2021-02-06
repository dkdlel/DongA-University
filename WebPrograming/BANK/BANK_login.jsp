<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>DB BANK</title></head>
<body style="background-color:#F8ECE0"> 
<div align="center"> 
	<%
	request.setCharacterEncoding("UTF-8"); 
	String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
	String uid = "scott";  String pass = "tiger";  
	String sql =  "select count from visit"; 
	try{ 
		Class.forName("oracle.jdbc.driver.OracleDriver"); 
		Connection conn = DriverManager.getConnection(url, uid, pass); 
		PreparedStatement pre = conn.prepareStatement(sql); 
		ResultSet rs = pre.executeQuery(); 
		rs.next();
		%>로그인 횟수 : <%= rs.getInt("count") %>
		<h1>DAU BANK</h1>  
		<form method="post" action="BANK_check_id.jsp">  
			ID: <input type="text" name="id"/> <p> 
			<input type="submit" value="login"/> &nbsp;&nbsp;       
			<a href="BANK_member.html" > 회원가입 </a> <p> 
		</form>   
	<%} catch (Exception e) { 
		out.print("visit 오류 발생" + e.getMessage()); 
	}%>
</div>

</body>
</html>