3p

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<%@ page import = "java.util.Date" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>DB 입금 확인</title></head>
<body>

<%
request.setCharacterEncoding("UTF-8"); 
String id = (String) session.getAttribute("id"); 
int deposit = Integer.parseInt(request.getParameter("deposit"));
String tradedate = "2018-11-05";
int withdraw = 0;
String url = "jdbc:oracle:thin:@localhost:1521:XE";
String uid = "scott"; String pass = "tiger";  
String sql =  "insert into banktrade values(?,?,?,?)"; 
try{
	Class.forName("oracle.jdbc.driver.OracleDriver"); 
	Connection conn = DriverManager.getConnection(url, uid, pass); 
	PreparedStatement pre = conn.prepareStatement(sql);    
	pre.setString(1,id); pre.setInt(2,deposit);
	pre.setInt(3,withdraw); pre.setString(4,tradedate);
	pre.executeUpdate();
	session.invalidate();
	%>
	<script> 
		alert("입금되었습니다."); 
		"1105_login.jsp"; 
	</script>
<%}
catch(Exception e){
	out.print("죄송합니다, 문제가 생겼습니다. <p>" + e.getMessage() + "<p>");
}
%>

</body>
</html>

 

---------------------------------------------------------------------------

 
3c

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>DB 입금 확인</title></head>
<body>

<%
request.setCharacterEncoding("UTF-8"); 
String id = request.getParameter("id"); 
int deposit = Integer.parseInt(request.getParameter("deposit"));
String url = "jdbc:oracle:thin:@localhost:1521:XE";
String uid = "scott"; String pass = "tiger";  
String sql =  "insert into banktrade values('" + id + "','" + deposit + "','" + 0 + "','" + "2018-11-05" + "')";
try{
	Class.forName("oracle.jdbc.driver.OracleDriver"); 
	Connection conn = DriverManager.getConnection(url, uid, pass); 
	Statement cre = conn.createStatement();   
	cre.executeUpdate(sql); 
	session.invalidate();
	%>
	<script>
		alert("입금되었습니다."); 
		"1105_login.jsp"; 
	</script>
<%}
catch(Exception e){
	out.print("죄송합니다, 문제가 생겼습니다. <p>" + e.getMessage() + "<p>");
}
%>

</body>
</html>