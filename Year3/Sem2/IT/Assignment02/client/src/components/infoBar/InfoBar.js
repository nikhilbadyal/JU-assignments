import React from 'react';
import './InfoBar.css';
import onlineIcon from '../../icons/onlineIcon.png';
import CancelOutlinedIcon from '@material-ui/icons/CancelOutlined';
import {makeStyles} from "@material-ui/core/styles";
import Avatar from "@material-ui/core/Avatar";


const useStyles = makeStyles((theme) => ({
    avatar: {

        margin: theme.spacing(0.2),
        backgroundColor: "#4CA1AF",
    },
}));

function InfoBar({room}) {
    const classes = useStyles();

    return <div className="infoBar">
        <div className="leftInnerContainer">
            <img className="onlineIcon" src={onlineIcon} alt="online img"/>
            <h3>{room}</h3>
        </div>

        <div className="middleInnerContainer">
            <h3>{"Assignment3 Chat Group"}</h3>
        </div>

        <div className="rightInnerContainer">

            <a href="/"><Avatar className={classes.avatar}>
                <CancelOutlinedIcon/>
            </Avatar></a>
        </div>

    </div>;
}

export default InfoBar;