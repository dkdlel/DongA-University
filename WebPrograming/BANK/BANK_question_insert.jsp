<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html><html><head><meta charset="UTF-8"><title>질의 응답</title></head>
<body>
<%
request.setCharacterEncoding("UTF-8"); 
String id = (String)session.getAttribute("id");
String Q_comments = request.getParameter("Q_comments");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";
String sql =  "select max(seq) from qanda";
String I_sql = "insert into qanda values(?,sysdate, ? , ?, '(preparing)')";
try{ 
	Class.forName("oracle.jdbc.driver.OracleDriver"); 
	Connection conn = DriverManager.getConnection(url, uid, pass); 
	PreparedStatement pre = conn.prepareStatement(sql);
	ResultSet rs = pre.executeQuery();
	rs.next();
	int seq = rs.getInt(1) + 1;
	pre = conn.prepareStatement(I_sql);
	pre.setInt(1,seq); pre.setString(2,id); pre.setString(3,Q_comments);
	pre.executeUpdate(); 
	response.sendRedirect("BANK_question.jsp");
	%> 
<%} catch (Exception e) {
	out.print("질의응답 중 오류가 발생했습니다<p>" + e.getMessage()); 
}
%>

</body>
</html>