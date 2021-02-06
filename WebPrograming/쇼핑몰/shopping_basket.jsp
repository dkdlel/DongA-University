<%@ page language="java" contentType="text/html; charset=UTF-8"  pageEncoding="UTF-8" import = "java.util.*"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>장바구니</title></head>

<body>

 

<form method="post" action="1011_shopping.jsp">

 

<%

request.setCharacterEncoding("UTF-8");

String id = (String)session.getAttribute("id");

String[] laptop =(String[])session.getAttribute("laptop");

String[] car =(String[])session.getAttribute("car");

%>

 

<h3>장바구니 목록</h3>

 

<%= id %>님이 선택하신 품목<p>

 

<%

if(laptop != null){

for(String l : laptop){ %>

<input type = "checkbox" name = "total" value="total_laptop"><%= l %><p><%

}

}

if(car != null){

for(String c : car){ %>

<input type = "checkbox" name = "total" value="total_car"><%= c %><p><%

}

}

%>

 

 

<p>입니다.<p> 구매하시겠습니까?<p>

<input type="submit" value="구매"/> &nbsp;

<a href = "http://localhost:8181/WebPrograming/1011_menu.jsp">

메뉴로 가기

</a>

 

</form>

 

</body>

</html>