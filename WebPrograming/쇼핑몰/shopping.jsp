<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>구매완료</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8");

String id = (String)session.getAttribute("id");

String[] laptop =(String[])session.getAttribute("laptop");

String[] car =(String[])session.getAttribute("car");

String[] total = request.getParameterValues("total");

 

 

long lasttime = session.getLastAccessedTime();

long createdtime = session.getCreationTime();

long time_used = (lasttime - createdtime) / 1000;

%>

 

<%

if(total != null){ 

 

String msg = " ";

if(laptop != null){ 

for(String l : laptop){ 

msg += l + ' ';

}

}

if(car != null){

for(String c : car){  

msg += c + ' ';

}

}

%>

<script> 

alert("<%= msg %>구매가 완료되었습니다. 오늘 쇼핑하신 시간은  <%=time_used%>초 입니다. 감사합니다."); 

"http://localhost:8181/WebPrograming/1011_menu.jsp"; 

</script>

<% 

session.removeAttribute("laptop");

session.removeAttribute("car");

}%>

 

<% if(total == null){ %>

 

<script> 

alert("구매 항목이 없습니다."); 

"http://localhost:8181/WebPrograming/1011_shopping_basket.jsp"; 

</script>

<% }%>

 

</body>

</html>