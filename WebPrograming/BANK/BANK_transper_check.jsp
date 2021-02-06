<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<%@ page import = "java.sql.*" %>

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>이체 확인</title></head>

<body>

 

<% 

request.setCharacterEncoding("UTF-8"); 

String id = (String)session.getAttribute("id"); 

String addressee = request.getParameter("addressee");

int trans_money = Integer.parseInt(request.getParameter("trans_money")); 

String url = "jdbc:oracle:thin:@localhost:1521:XE"; 

String uid = "scott";  String pass = "tiger"; 

String sql =  "select balance from bankmember where id = ?";

try{ 

Class.forName("oracle.jdbc.driver.OracleDriver"); 

Connection conn = DriverManager.getConnection(url, uid, pass); 

PreparedStatement pre = conn.prepareStatement(sql);

pre.setString(1,addressee);

ResultSet rs = pre.executeQuery();

// 아이디 체크

if(rs.next()) { 

pre.setString(1,id);

ResultSet rs2 = pre.executeQuery();

rs2.next();

// 잔액확인

int balance = rs2.getInt("balance"); 

if(balance >= trans_money) { // 잔액이 충분해야 출금 진행 

session.setAttribute("addressee",addressee);

session.setAttribute("trans_money",trans_money);

response.sendRedirect("BANK_transper_update.jsp");

}// 아이디 존재 확인 괄호

%>

<script> 

alert("잔액이 부족합니다 (현재 잔액: <%=balance%> 원)"); 

"http://localhost:8181/WebPrograming/BANK_transper.jsp";

</script>

<%

} %>

<script> 

alert("<%=addressee%>님은 존재하지 않은 아이디 입니다."); 

"http://localhost:8181/WebPrograming/BANK_transper.jsp";

</script>

<%

} // try 괄호

catch (Exception e) {

out.print("이체 진행 중 오류가 발생했습니다<p>" + e.getMessage()); 

}

%>

 

</body>

</html>