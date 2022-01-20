package com.nikhil.assignment04.dao;

import com.nikhil.assignment04.model.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Insert {

    public boolean insertUserData(User user, Connection conn) {

        boolean res = false;

        String sql = "insert into shoppingStore.user values(?, ?, ?, ?, ?, ?,?,?)";
        try {
            PreparedStatement st = conn.prepareStatement(sql);
            st.setString(1, user.getFname());
            st.setString(2, user.getLname());
            st.setString(3, user.getEmail());
            st.setString(4, user.getPassword());
            st.setString(5, user.getGender());
            st.setString(6, user.getPrefer());

            res = st.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return res;

    }

}
