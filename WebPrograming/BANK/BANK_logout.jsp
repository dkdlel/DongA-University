<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>로그아웃</title></head>

<body>

 

<%

request.setCharacterEncoding("UTF-8");

String id = (String)session.getAttribute("id");

session.invalidate(); 

%>

<div align="center">

<strong>로그아웃하였습니다. <%= id %>님, 또 방문해 주세요!</strong><p>

첫화면으로 가시려면 아래 그림을 클릭해 주세요~<p>

<a href = "BANK_login.jsp" >

<img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1119 과제\\자까.jpg" width="300" height="200" alt="왜 안드죠ㅠㅠ"> 

</a>

</div>

</body>

</html>