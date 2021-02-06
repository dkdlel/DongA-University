<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<%@ page import = "java.sql.*" %>

<!DOCTYPE html><html><head><meta charset="UTF-8"><title>질의 응답</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8"); 

String id = (String)session.getAttribute("id");

String url = "jdbc:oracle:thin:@localhost:1521:XE"; 

String uid = "scott";  String pass = "tiger";

String sql =  "select * from qanda";

 

try{ 

Class.forName("oracle.jdbc.driver.OracleDriver"); 

Connection conn = DriverManager.getConnection(url, uid, pass); 

PreparedStatement pre = conn.prepareStatement(sql);

ResultSet rs = pre.executeQuery();

%> 

 

<font color="blue"><%=id%></font>님, 궁금하신 점이 있으세요? 질문을 주시면 답을 해드립니다.<p><p>

 

<table border="1">

<tr>

<th>seq</th> <th>질문일자</th> <th>ID</th> <th>Question</th> <th>Answer</th>

</tr>

<tr>

<% while(rs.next()){ %>

<th><%= rs.getInt("seq") %></th>

<th><%= rs.getString("qdate") %></th>

<th><%= rs.getString("id") %></th>

<th><%= rs.getString("question") %></th> 

<th><%= rs.getString("answer") %></th>

</tr>

<%} %>

</table> <p><p>

<form method="post" action="BANK_question_insert.jsp">

질문 입력 : <br>

<textarea name="Q_comments" rows="4" cols="40">입력하세용~ </textarea>

<input type ="submit" value = "질문등록"/>

</form>

<% 

if(id!=null) 

{ 

if(id.equals("admin")) {%>

<p><jsp:include page="BANK_answer.jsp" flush="false"/>

<%}

} %>

<a href = "BANK_menu.jsp">메뉴로 돌아가기</a>

 

<%} catch (Exception e) {

out.print("질의응답 중 오류가 발생했습니다<p>" + e.getMessage()); 

}

%>

</body>

 

</html>