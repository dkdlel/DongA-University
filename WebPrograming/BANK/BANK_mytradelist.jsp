<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>거래</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

String id = (String) session.getAttribute("id");

Integer total_money = (Integer) session.getAttribute("total_money");

Integer input_check = (Integer) session.getAttribute("input_check");

Integer output_check = (Integer) session.getAttribute("output_check");

%>

 

<%= id %>님의 거래 현황<p>

<ul>

      <li>현재 잔액 :&nbsp; <%=total_money %><p>

      <li>입금 횟수 :&nbsp; <%=input_check %><p>

      <li>출금 횟수 :&nbsp; <%=output_check %><p>

   </ul>

   <a href="http://localhost:8181/WebPrograming/1001_menu.jsp">메뉴</a>

</body>

</html>