package com.nikhil.assignment03.admin.dao;

import com.nikhil.assignment03.admin.model.Flight;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;


public class FlightAddDao {
    private final Connection conn;

    public FlightAddDao(Connection conn) {
        this.conn = conn;
    }


    public void insert(Flight flightDetails) {
        String sql = "insert into traveldatabase.flight values(?,?,?,?,?,?,?,?,?,?,?)";
        try {
            try (PreparedStatement st = conn.prepareStatement(sql)) {
                st.setString(1, flightDetails.getCompany());
                st.setInt(2, flightDetails.getFno());
                st.setString(3, flightDetails.getSrc());
                st.setString(4, flightDetails.getDest());
                st.setString(5, flightDetails.getDeptDate());
                st.setString(6, flightDetails.getDeptTime());
                st.setInt(7, flightDetails.getCapacity());
                st.setInt(8, flightDetails.getSeatLeft());
                st.setInt(9, flightDetails.getPrice());
                st.setString(10, flightDetails.getSpecialOffer());
                st.setString(11, flightDetails.getSpecialLimit());

                st.executeUpdate();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }


}
