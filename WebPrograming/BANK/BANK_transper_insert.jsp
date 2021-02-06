<%@ page language="java" contentType="text/html; charset=UTF-8"

    pageEncoding="UTF-8"%>

<%@ page import ="java.sql.*" %> 

<!DOCTYPE html>

<html><head><meta charset="UTF-8"><title>이체</title></head><body>

 

<% 

request.setCharacterEncoding("UTF-8"); 

String id = (String)session.getAttribute("id"); 

String addressee = (String)session.getAttribute("addressee"); 

int trans_money = (Integer)session.getAttribute("trans_money");

 

String url = "jdbc:oracle:thin:@localhost:1521:XE"; 

String uid = "scott";  String pass = "tiger"; 

String I_sql = "insert into banktrade values(?,sysdate, 0, ? , 1, ?)"; // 주는사람

String I_sql2 = "insert into banktrade values(?,  sysdate, ? , 0, 2, ?)"; // 받는사람

String U_sql = "update bankmember set balance=balance-? where id=?"; 

String U_sql2 = "update bankmember set balance=balance+? where id=?"; 

try{ 

Class.forName("oracle.jdbc.driver.OracleDriver"); 

Connection conn = DriverManager.getConnection(url, uid, pass); 

// james 출금

PreparedStatement pre = conn.prepareStatement(I_sql);

pre.setString(1,id); pre.setInt(2,trans_money); pre.setString(3,addressee);

pre.executeUpdate(); 

// james balance update

pre = conn.prepareStatement(U_sql);

pre.setInt(1,trans_money); pre.setString(2,id);

pre.executeUpdate(); 

// tom 입금

pre = conn.prepareStatement(I_sql2); 

pre.setString(1,addressee); pre.setInt(2,trans_money); pre.setString(3,id);

pre.executeUpdate(); 

// tom balance update

pre = conn.prepareStatement(U_sql2);

pre.setInt(1,trans_money); pre.setString(2,addressee);

pre.executeUpdate();

%> 

<script> 

alert("이체가 완료되었습니다~"); 

"BANK_menu.jsp"; 

</script> 

<%} catch (Exception e) {

out.print("이체 진행 중 오류가 발생했습니다<p>" + e.getMessage()); 

}

%>

 

</body>

</html>