<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>로그아웃</title></head>
<body>
<% session.invalidate(); %> 
<script> 
	alert("로그아웃 되었습니다."); 
	"http://localhost:8181/WebPrograming/1011_login.html"; 
</script>

 </body>
</html>