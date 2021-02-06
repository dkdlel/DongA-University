<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>출금</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

%>

<h3>출금화면</h3><p>

<form method="post" action="1001_outputcheck.jsp"> 

금액을 입력하세요.<p>

출금액 : <input type = "text" name = "output_money"/><p>

<input type = "submit" value = "확인"/> &nbsp;

<a href = "http://localhost:8181/WebPrograming/1001_login.html">

메뉴로 가기

</a>

</form>

</body>

</html>