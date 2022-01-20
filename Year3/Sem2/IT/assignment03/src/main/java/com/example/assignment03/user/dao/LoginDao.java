package com.nikhil.assignment03.user.dao;

import com.nikhil.assignment03.user.model.CustomerModelForLogin;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class LoginDao {
    private final Connection conn;

    public LoginDao(Connection conn) {
        this.conn = conn;
    }

    public boolean check(CustomerModelForLogin customerModelForLogin) {
        String sql = "select username, password from traveldatabase.customer where username=? and password=?";
        try {
            ResultSet rs;
            System.out.println("Hello there1");
            PreparedStatement st = conn.prepareStatement(sql);
            st.setString(1, customerModelForLogin.getUsername());
            st.setString(2, customerModelForLogin.getPassword());
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
