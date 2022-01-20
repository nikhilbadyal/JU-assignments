package com.nikhil.assignment04.controller;


import com.nikhil.assignment04.dao.LoginDao;
import com.nikhil.assignment04.model.User;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet("/Login")
public class Login extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.sendRedirect("login_register.jsp");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String email = request.getParameter("email");
        String pass = request.getParameter("pass");

        HttpSession session = request.getSession();

        ResultSet rs;
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
        LoginDao loginDao = new LoginDao();

        rs = loginDao.checkLogin(email, pass, conn);

        if (rs != null) {

            User user = null;

            try {
                user = new
                        User(rs.getString("fname"), rs.getString("lname"),
                        rs.getString("email"), rs.getString("password"),
                        rs.getString("gender"), rs.getString("prefer"),
                        Integer.parseInt(rs.getString("newTracker")),
                        Integer.parseInt(rs.getString("discountTracker")));
            } catch (SQLException e) {
                e.printStackTrace();
            }
            session.setAttribute("user", user);
            response.sendRedirect("home.jsp");
        } else {
            session.invalidate();
            request.setAttribute("errorMessage", "Invalid Email or wrong password");
            RequestDispatcher rd = request.getRequestDispatcher("login_register.jsp");
            rd.forward(request, response);

        }
    }

}
