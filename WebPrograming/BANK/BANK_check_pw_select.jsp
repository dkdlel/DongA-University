<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>비밀번호 체크</title></head>
<body>

<%
request.setCharacterEncoding("UTF-8");
String pw = request.getParameter("pw");
String id = (String)session.getAttribute("id"); 
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql = "select * from bankmember where id = ?";
try { 
	Class.forName("oracle.jdbc.driver.OracleDriver"); 
	Connection conn = DriverManager.getConnection(url, uid, pass); 
	PreparedStatement  pre = conn.prepareStatement(sql);
	pre.setString(1,id);
	ResultSet rs = pre.executeQuery();
	rs.next();
	if(pw.equals(rs.getString("pw"))){
		response.sendRedirect("BANK_myinfo.jsp");
	}
	else{
	%>
	<script> 
		alert("비밀번호를 틀리게 입력하셨어요."); 
		"http://localhost:8181/WebPrograming/BANK_check_pw.jsp"; 
	</script>
	<%}
} catch (Exception e) { 
	out.print("죄송합니다, 문제가 생겼어요ㅠ  <p>" + e.getMessage()); 
} %>

</body>
</html>

 