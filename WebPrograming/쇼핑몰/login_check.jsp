<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html><html><head><meta charset="UTF-8"><title>로그인 확인</title></head>
<body>

<%
request.setCharacterEncoding("UTF-8");
String ID = request.getParameter("id");
String PW = request.getParameter("pw");
String[] members = {"a","b","c","d","e"};
String[] password = {"1","2","3","4","5"};
for(int i = 0 ; i < 5 ; i ++){
	if(ID.equals(members[i])){
		if(PW.equals(password[i])){
			session.setAttribute("id",ID);
			session.setAttribute("pw",PW); 
			session.setMaxInactiveInterval(60*60);  // 테스트 편의 위해 1시간 
			response.sendRedirect("1011_menu.jsp");
		}
		else{
		%>
			<script>
				alert("비밀번호가 틀렸습니다.");
				"http://localhost:8181/WebPrograming/1011_login.html";
			</script>
		<%}
	}
}
%>
<script>
	alert("미등록 아이디 입니다~");
	"http://localhost:8181/WebPrograming/1011_login.html";
</script>
 
</body>
</html>