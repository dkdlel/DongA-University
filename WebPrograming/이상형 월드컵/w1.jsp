<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>4강 A</title></head>
<body>
<div align="center"> 
	<h2>야식 1인자를 가리자!!</h2>
	<form method="post" action="1122_w2.jsp">
		<table width="500"> 
			<tr>
				<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\족발.jpg" width=300 height=300 alt="족발"></td>
				<td><img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\기말고사\\1122 과제\\떡볶이.jpg" width=300 height=300 alt="떡볶이"></td>
			</tr>
			<tr>
				<th><input type = "radio" name = "w1winner" value = "족발"> 족발 </th>
				<th><input type = "radio" name = "w1winner" value = "떡볶이"> 떡볶이 </th>
			</tr>
		</table>
		<input type = "submit" value = "선택">
	</form>
</div>

</body>
</html>