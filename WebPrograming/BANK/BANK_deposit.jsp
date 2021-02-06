<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>DB 입금</title></head>
<body>

<form method="post" action="1105_deposit_check.jsp"> 
	<%
	String id = request.getParameter("id");
	session.setAttribute("id",id);
	%>
	<%= id %>님 입금화면 <p>
	입금액 : <input type ="text" name="deposit"/>원<p>
	<input type = "submit" value="입금"/>
</form>

</body>
</html>