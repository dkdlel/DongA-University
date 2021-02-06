<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>자동차 저장</title></head>

<body>

 

<%

request.setCharacterEncoding("UTF-8");

String[] car = request.getParameterValues("car");

 

if(car == null){%>

<script> 

alert("선택된것이 없습니다."); 

"http://localhost:8181/WebPrograming/1011_menu.jsp"; 

</script>

<%

}

else{

session.setAttribute("car",car);

} %><p><p>

 

<script> 

alert("장바구니에 추가되었습니다."); 

"http://localhost:8181/WebPrograming/1011_menu.jsp"; 

</script>

 

</body>

</html>