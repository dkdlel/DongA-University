<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>노트북</title></head>

<body>

<h3>노트북</h3><p>

 

<form method="post" action="1011_save_laptop.jsp">

 

<table border="1">

<tr>

<td> <input type="checkbox" name="laptop" value="gram"/> </td> <td> LG gram </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\gram.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="laptop" value="samsung"/> </td> <td> Samsung </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\samsung.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="laptop" value="msi"/> </td> <td> msi </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\msi.jpg"> </td>

</tr>

 

<tr>

<td> <input type="checkbox" name="laptop" value="MacBook"/> </td> <td> MacBook </td> <td> <img src="C:\\Users\\JeJn\\Desktop\\2018\\2학기\\웹프로그래밍\\1011과제\\MacBook.jpg"> </td>

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