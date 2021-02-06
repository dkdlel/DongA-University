<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>자동차</title></head>

<body>

 

<h3>선호하는 자동차</h3><p>

 

<form method="post" action="1011_save_car.jsp">

 

<table border="1">

<tr>

 

<tr>

<td> <input type="checkbox" name="car" value="BMW"/> </td> <td> BMW </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\BMW.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="car" value="Benz"/> </td> <td> Benz </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\Benz.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="car" value="Audi"/> </td> <td> Audi </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\Audi.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="car" value="Maserati"/> </td> <td> Maserati </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\Maserati.jpg"> </td>

</tr>

 

</table>

<p>

 

<input type="submit" value="장바구니 추가"/> &nbsp;

<a href = "http://localhost:8181/WebPrograming/1011_menu.jsp">

메뉴로 가기

</a>

 

</form>

</body>

</html>