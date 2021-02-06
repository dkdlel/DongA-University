<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>4강 B</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

String w1winner = request.getParameter("w1winner");

session.setAttribute("w1winner",w1winner);

%>

<div align="center"> 

<h2>야식 1인자를 가리자!!</h2>

<form method="post" action="1122_w3.jsp">

<table width="500"> 

<tr>

<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\치킨.jpg" width=300 height=300 alt="치킨"></td>

<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\피자.jpg" width=300 height=300 alt="피자"></td>

</tr>

<tr>

<th><input type = "radio" name = "w2winner" value = "치킨"> 치킨 </th>

<th><input type = "radio" name = "w2winner" value = "피자"> 피자 </th>

</tr>

</table>

<input type = "submit" value = "선택">

</form>

</div>

</body>

</html>