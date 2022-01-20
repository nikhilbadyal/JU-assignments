package com.nikhil.assignment03.admin.controller;

import com.nikhil.assignment03.admin.dao.LoginDao;
import com.nikhil.assignment03.admin.model.Admin;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;

@WebServlet("/managementTeam/AdminLogin")
public class Login extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String eid = request.getParameter("eid");
        String ecode = request.getParameter("ecode");
        PrintWriter out = response.getWriter();

        Admin admin = new Admin(eid, ecode);
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");

        LoginDao alDao = new LoginDao(conn);
        if (alDao.check(admin)) {

            HttpSession session = request.getSession();

            session.setAttribute("admin", admin);
            response.sendRedirect("flightDetails.jsp");
        }else {

            out.println("<script src='https://cdnjs.cloudflare.com/ajax/l" +
                    "ibs/limonte-sweetalert2/6.11.4/sweetalert2.all.js'></script>");
            out.println("<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>");
            out.println("<script>");
            out.println("$(document).ready(function(){");
            out.println("swal('incorrect Employee ID or Employee CODE', '', 'error');");
            out.println("});");
            out.println("</script>");


            RequestDispatcher rd = request.getRequestDispatcher("managerlogin.jsp");
            rd.include(request, response);

        }
    }
}
