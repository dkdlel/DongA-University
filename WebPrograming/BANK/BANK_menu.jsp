<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>메뉴</title></head>

<body>

<h3>메뉴</h3>

<%

request.setCharacterEncoding("UTF-8");

String id = (String) session.getAttribute("id");

%>

<%= id %>님 반가워요~<p><p>

<a href = "1001_input.jsp">

1.입금

</a><p>

<a href = "1001_output.jsp">

2.출금

</a><p>

<a href = "1001_deal.jsp">

3.나의거래

</a><p>

<a href = "1001_logout.jsp">

4.로그아웃

</a><p>

 

</body>

</html>