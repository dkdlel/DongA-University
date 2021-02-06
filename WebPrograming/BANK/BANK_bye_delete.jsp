<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import = "java.sql.*" %>
<!DOCTYPE html>
<html><head><meta charset="UTF-8"><title>회원정보 삭제</title></head>
<body>
<%
request.setCharacterEncoding("UTF-8"); 
String id = (String)session.getAttribute("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";
String sql =  "select * from bankmember where id = ?"; 
String D_sql = "delete from bankmember where id = ?";
String I_sql = "insert into bankmember_tal values(?,?,?,?,?,?)";
 
try{ 
Class.forName("oracle.jdbc.driver.OracleDriver"); 
Connection conn = DriverManager.getConnection(url, uid, pass); 
PreparedStatement pre = conn.prepareStatement(sql);
pre.setString(1,id); 
ResultSet rs = pre.executeQuery(); 
rs.next();
String pw = rs.getString("pw"); String name = rs.getString("name"); 
int age = rs.getInt("age"); String phone = rs.getString("phone");
int balance = rs.getInt("balance");
 
pre = conn.prepareStatement(D_sql);
pre.setString(1,id); 
pre.executeUpdate();
pre = conn.prepareStatement(I_sql);
pre.setString(1,id); pre.setString(2,pw); pre.setString(3,name);
pre.setInt(4,age); pre.setString(5,phone); pre.setInt(6,balance); 
pre.executeUpdate(); 
session.invalidate(); 
%>
<script>
alert("회원 탈퇴처리 되었습니다. 하지만 신분증을 가지고 은행에 오시면 잔액을 인출하실 수 있습니다. 다음에 또 뵙기를 바랍니다!!(첫화면으로 이동합니다)");
"BANK_login.jsp";
</script>
<%} catch (Exception e) { 
out.print("회원탈퇴 중 문제 발생 <p>" + e.getMessage()); 
}
%>
</body>
</html>