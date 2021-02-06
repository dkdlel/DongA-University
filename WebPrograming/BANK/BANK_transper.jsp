<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>자동이체</title></head>

<body>

 

<div align = "center">

<h2> 자동이체 </h2>

<form method="post" action="BANK_transper_check.jsp"> 

&nbsp;수 신 인 &nbsp;: <input type = "text" name = "addressee"/><p>

이체금액 : <input type = "text" name = "trans_money"/><p>

<input type = "submit" value = "이체실행"/>

</form>

</div>

 

</body>

</html>