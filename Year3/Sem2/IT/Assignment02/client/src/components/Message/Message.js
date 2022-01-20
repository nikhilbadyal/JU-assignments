import React from 'react';
//import ScrollToBottom from 'react-scroll-to-bottom';
import Image from '../Image/Image';
import './Message.css';



const Message = ({data, name}) => {
    if(data.type === "file"){
        const blob = new Blob([data.body], {type: data.type});
        const trimmedName= name.trim().toLowerCase();
        if(data.user === trimmedName){
            return (
                <div className="messageContainer justifyEnd">
                    <p className="sentText pr-10">{trimmedName}</p>
                    <div className="messageBox backgroundBlue">
                        <Image filename={data.filename} blob={blob}></Image>
                    </div>
                </div>
            )
        }else{
            return (
                <div className="messageContainer justifyStart">
                    <div className="messageBox backgroundLight">
                        <Image filename={data.filename} blob={blob}></Image>
                    </div>
                    <p className="sentText pl-10">{data.user}</p>
                </div>
            )
        }
    }else{
        let isSentByCurrentUser = false;
        const trimmedName= name.trim().toLowerCase();

        const user = data.user;
        const text = data.body;

        if(user === trimmedName){
            isSentByCurrentUser = true;
        }

        return (
            isSentByCurrentUser
                ?(
                    <div className="messageContainer justifyEnd">
                        <p className="sentText pr-10">{trimmedName}</p>
                        <div className="messageBox backgroundBlue">
                            <p className="messageText colorWhite"> {text}</p>
                        </div>
                    </div>
                )
                :(
                    <div className="messageContainer justifyStart">
                        <div className="messageBox backgroundLight">
                            <p className="messageText colorDark"> {text}</p>
                        </div>
                        <p className="sentText pl-10">{user}</p>
                    </div>
                )
        )
    }
}

export default Message;