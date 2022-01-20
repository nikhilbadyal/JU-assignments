package com.nikhil.assignment03.admin.dao;

import com.nikhil.assignment03.admin.model.Admin;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginDao {
    private final Connection conn;

    public LoginDao(Connection conn) {
        this.conn = conn;
    }

    public boolean check(Admin admin) {
        String sql = "select * from traveldatabase.admin where eid=? and ecode=?";
        try {
            ResultSet rs;
            PreparedStatement st = conn.prepareStatement(sql);
            st.setString(1, admin.getEid());
            st.setString(2, admin.getEcode());
            rs = st.executeQuery();

            if (rs.next()) {
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();

        }
        return false;

    }

}
