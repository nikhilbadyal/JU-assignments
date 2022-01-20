package com.nikhil.assignment04.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginDao {
    public ResultSet checkLogin(String email, String pass, Connection conn) {


        String sql = "select * from shoppingStore.user where email='" + email + "' and password='" + pass + "'";
        try {
            PreparedStatement st = conn.prepareStatement(sql);
            ResultSet rs = st.executeQuery();
            if (rs.next()) {
                return rs;
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();

        }
        return null;

    }
}
