package com.nikhil.assignment03.user.controller;

import com.nikhil.assignment03.user.dao.RegisterDao;
import com.nikhil.assignment03.user.model.Customer;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.Connection;


@WebServlet("/user/Register")
public class Register extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String uname = request.getParameter("uname");
        String email = request.getParameter("email");
        String password = request.getParameter("password");
        String phone = request.getParameter("phone");
        String address = request.getParameter("address");

        Customer customer = new Customer(uname, email, password, phone, address);
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");

        RegisterDao rDao = new RegisterDao(conn);
        boolean res = rDao.insert(customer);
        response.getWriter().print(res);
        response.sendRedirect("user_register.jsp");
    }

}
