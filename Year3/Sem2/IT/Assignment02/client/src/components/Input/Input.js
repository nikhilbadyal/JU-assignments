import React from 'react';
import './Input.css';
import {makeStyles} from "@material-ui/core/styles";
import SendOutlined from '@material-ui/icons/SendOutlined';
import CancelOutlinedIcon from "@material-ui/icons/CancelOutlined";
import Avatar from "@material-ui/core/Avatar";
import {Send} from "@material-ui/icons";

const useStyles = makeStyles((theme) => ({
    avatar: {

        margin: theme.spacing(0.2),
        backgroundColor: "#4CA1AF",
    },
}));

function Input({message, setMessage, sendMessage, selectFile}) {
    const classes = useStyles();

    return (
        <form className="form">
            <input
                className="input"
                type="text" placeholder="type a message"
                value={message} onChange={event => setMessage(event.target.value)}
                onKeyPress={event => event.key === "Enter" ? sendMessage(event) : null}>
            </input>
            <input id="inputFileToLoad" type="file" onChange={event => selectFile(event)}/>
            <Avatar className={classes.avatar} onClick={event => sendMessage(event)}>
                <SendOutlined/>
            </Avatar>
            {/*<button className="sendButton" onClick={event => sendMessage(event)}>Send</button>*/}
        </form>
    )
}

export default Input;