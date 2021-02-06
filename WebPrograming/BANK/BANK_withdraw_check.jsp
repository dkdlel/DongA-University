<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>출금액 확인</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

Integer total_money = (Integer)session.getAttribute("total_money");

Integer output_check = (Integer)session.getAttribute("output_check");

String temp = request.getParameter("output_money");

Integer money = Integer.parseInt(temp);

 

if(total_money < money){ %>

<script>

alert("잔액이 부족합니다.");

"http://localhost:8181/WebPrograming/1001_menu.jsp";;

</script>

<%}

else{

total_money -= money;

output_check++;

session.setAttribute("total_money",total_money);

session.setAttribute("output_check",output_check);

%>

<script>

alert("출금이 완료되었습니다.");

"http://localhost:8181/WebPrograming/1001_menu.jsp";

</script>

<%} %>

</body>

</html>