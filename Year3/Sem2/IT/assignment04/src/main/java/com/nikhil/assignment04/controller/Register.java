package com.nikhil.assignment04.controller;


import com.nikhil.assignment04.dao.Insert;
import com.nikhil.assignment04.model.User;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;


@WebServlet("/Register")
public class Register extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {

        String fname = request.getParameter("first_name");
        String lname = request.getParameter("last_name");
        String email = request.getParameter("email");
        String pass = request.getParameter("password");
        String gender = request.getParameter("gender");
        String prefer = request.getParameter("prefer");
        int newTracker = 0;
        int discountTracker = 0;


        User user = new User(fname, lname, email,
                pass, gender, prefer, newTracker, discountTracker);
        Insert insert = new Insert();
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");

        boolean res = insert.insertUserData(user, conn);

        response.getWriter().println(res);

        HttpSession session = request.getSession();
        if (res) {
            session.setAttribute("message", "Register Success");
        } else {
            session.setAttribute("message", "Register Fails");
        }
        response.sendRedirect("login_register.jsp");
    }


}
