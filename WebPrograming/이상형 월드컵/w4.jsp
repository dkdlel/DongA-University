<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>결과</title></head>
<body>

<%
request.setCharacterEncoding("UTF-8");
String final_winner = request.getParameter("final_winner");
%>
<div align="center"> 
	<table width="500"> 
		<tr>
			<th><h2>최종 우승은 <font color = "blue"><%= final_winner %></font> 입니다~</h2></th>
		</tr>
		<tr>
			<th><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\<%=final_winner %>.jpg" width=300 height=300 alt="<%=final_winner %>"></th>
		</tr>
	</table>
</div>

</body>
</html>