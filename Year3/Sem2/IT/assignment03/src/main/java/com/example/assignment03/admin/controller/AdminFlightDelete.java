package com.nikhil.assignment03.admin.controller;

import com.nikhil.assignment03.admin.dao.FlightDelete;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.Connection;


@WebServlet("/managementTeam/AdminFlightDelete")
public class AdminFlightDelete extends HttpServlet {


    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int fnum = Integer.parseInt(request.getParameter("fnum"));
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");

        FlightDelete deleteDao = new FlightDelete(conn);
        boolean rowdelete = deleteDao.delete(fnum);
        if (rowdelete) {
            RequestDispatcher rd = request.getRequestDispatcher("flightDetails.jsp");
            rd.include(request, response);
        } else {
            response.sendRedirect("flightDetails.jsp");
        }

    }

}
