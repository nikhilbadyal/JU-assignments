package com.nikhil.assignment03.admin.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class FlightDelete {
    private final Connection conn;

    public FlightDelete(Connection conn) {
        this.conn = conn;
    }

    public boolean delete(int fno) {
        boolean rowdelete = false;


        String sql = "delete from traveldatabase.flight where fno=" + fno;
        try {
            try (PreparedStatement st = conn.prepareStatement(sql)) {

                rowdelete = st.executeUpdate() > 0;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return rowdelete;

    }
}
