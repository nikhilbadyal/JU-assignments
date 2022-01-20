<%@ page contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Book flight</title>
</head>
<body>
<%
	String userName = (String) request.getSession().getAttribute("username");
	if (userName == null) {
		response.sendRedirect("userlogin.jsp");
		return;
	}
%>
	<h4>I booked the ticket for free. Just for you</h4>

</body>
</html>