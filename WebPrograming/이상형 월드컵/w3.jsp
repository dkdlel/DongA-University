<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>결승</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

String w1winner = (String)session.getAttribute("w1winner");

String w2winner = request.getParameter("w2winner");

%>

<div align="center"> 

<h2>야식 1인자를 가리자!!</h2>

<form method="post" action="1122_w4.jsp">

<table width="500"> 

<tr>

<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\<%=w1winner %>.jpg" width=300 height=300 alt="<%=w1winner %>"></td>

<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\<%=w2winner %>.jpg" width=300 height=300 alt="<%=w2winner %>"></td>

</tr>

<tr>

<th><input type = "radio" name = "final_winner" value = "<%=w1winner %>"> <%=w1winner %> </th>

<th><input type = "radio" name = "final_winner" value = "<%=w2winner %>"> <%=w2winner %> </th>

</tr>

</table>

<input type = "submit" value = "선택">

</form>

</div>

</body>

</html>