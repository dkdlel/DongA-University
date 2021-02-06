<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html><html><head><meta charset="UTF-8"><title>질의 응답</title></head>
<body>
<%
	request.setCharacterEncoding("UTF-8"); 
	String id = (String)session.getAttribute("id");
%> 

<form method="post" action="BANK_answer_update.jsp">
	답변 입력 : <br>
	seq: <input type = "text" name = "seq_num" size="1"/><br>
	<textarea name="A_comments" rows="4" cols="40">입력하세용~ </textarea>
	<input type ="submit" value = "답변등록"/> <p>
</form>

</body>
</html>