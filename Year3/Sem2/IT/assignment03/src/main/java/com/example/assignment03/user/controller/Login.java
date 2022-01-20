package com.nikhil.assignment03.user.controller;

import com.nikhil.assignment03.user.dao.LoginDao;
import com.nikhil.assignment03.user.dao.Userdao;
import com.nikhil.assignment03.user.model.Customer;
import com.nikhil.assignment03.user.model.CustomerModelForLogin;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;

import java.io.IOException;
import java.sql.Connection;


@WebServlet("/user/Login")
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {

        String username = request.getParameter("username");
        String password = request.getParameter("pass");


        CustomerModelForLogin customerModelForLogin = new CustomerModelForLogin(username, password);
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
        LoginDao lDao = new LoginDao(conn);
        HttpSession session = request.getSession();

        if (lDao.check(customerModelForLogin)) {
            Userdao userDao = new Userdao(conn);
            Customer customer = userDao.get(customerModelForLogin);
            session.setAttribute("username", customerModelForLogin.getUsername());
            session.setAttribute("customer", customer);
            response.sendRedirect("../home.jsp");
        } else {
            session.setAttribute("customer", null);
            response.sendRedirect("userlogin.jsp");
        }
    }


}
