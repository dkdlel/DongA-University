<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<%@ page import = "java.sql.*" %> <%@ page import = "java.util.*" %>

<!DOCTYPE html><html><head><meta charset="UTF-8"><title>질의 응답</title></head>

<body>

<%

request.setCharacterEncoding("UTF-8"); 

String id = (String)session.getAttribute("id");

String A_comments = request.getParameter("A_comments");

int seq_num = Integer.parseInt(request.getParameter("seq_num"));

 

String url = "jdbc:oracle:thin:@localhost:1521:XE"; 

String uid = "scott";  String pass = "tiger";

String sql =  "select max(seq) from qanda";

String U_sql = "update qanda set answer = ? where seq = ?";

 

try{ 

Class.forName("oracle.jdbc.driver.OracleDriver"); 

Connection conn = DriverManager.getConnection(url, uid, pass);

PreparedStatement pre = conn.prepareStatement(sql);

ResultSet rs = pre.executeQuery();

rs.next();

int seq = rs.getInt(1);

// 입력받은 숫자가 더 크면

if(seq < seq_num){%>

<script> 

alert("입력하신 질문 번호가 존재하지 않습니다."); 

"BANK_question.jsp"; 

</script> 

<%}

else {

pre = conn.prepareStatement(U_sql);

pre.setString(1,A_comments); pre.setInt(2,seq_num);

pre.executeUpdate(); 

response.sendRedirect("BANK_question.jsp");

}

%> 

 

<%} catch (Exception e) {

out.print("질의응답 중 오류가 발생했습니다<p>" + e.getMessage()); 

}

%>

 

</body>

 

</html>