<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>메뉴</title></head>
<body>
<h3>메뉴</h3>
<%
request.setCharacterEncoding("UTF-8");
String id = (String) session.getAttribute("id");
%>
현재 <%= id %>의 계정으로 로그인 되어있습니다.<p><p>
<a href = "1011_laptop.jsp">
	1. 노트북
</a><p>
<a href = "1011_car.jsp">
	2. 자동차
</a><p>
<a href = "1011_shopping_basket.jsp">
	3. 장바구니
</a><p>
<a href = "1011_logout.jsp">
	4. 로그아웃
</a><p>

</body>
</html>