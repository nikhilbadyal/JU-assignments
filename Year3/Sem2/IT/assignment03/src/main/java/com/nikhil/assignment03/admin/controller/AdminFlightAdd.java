package com.nikhil.assignment03.admin.controller;

import com.nikhil.assignment03.admin.dao.FlightAddDao;
import com.nikhil.assignment03.admin.model.Flight;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.sql.Connection;

@WebServlet("/managementTeam/AdminFlightAdd")


public class AdminFlightAdd extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String company = request.getParameter("company");
        int fno = Integer.parseInt(request.getParameter("fno"));
        String src = request.getParameter("src");
        String dest = request.getParameter("dest");
        String deptDate = request.getParameter("deptDate");
        String deptTime = request.getParameter("deptTime");
        int capacity = Integer.parseInt(request.getParameter("capacity"));
        int seatLeft = Integer.parseInt(request.getParameter("seatLeft"));
        int price = Integer.parseInt(request.getParameter("price"));
        String specialOffer = request.getParameter("specialOffer");
        String specialLimit = request.getParameter("specialLimit");

        Flight admin = new Flight(company, fno, src, dest,
                deptDate, deptTime, capacity,
                seatLeft, price, specialOffer, specialLimit);
        Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
        FlightAddDao afDao = new FlightAddDao(conn);
        afDao.insert(admin);
        response.sendRedirect("flightDetails.jsp");

    }

}
