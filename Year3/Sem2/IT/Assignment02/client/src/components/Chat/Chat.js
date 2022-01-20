import InfoBar from '../infoBar/InfoBar';
import Input from '../Input/Input';
import React, {useEffect, useState} from "react";
import queryString from 'query-string';
import io from 'socket.io-client';
import Messages from '../Messages/Messages';
import TextContainer from "../TextContainer/TextContainer";
import './Chat.css';

const ENDPOINT = 'localhost:5000';
let socket;

const Chat = ({ location }) => {
  const [name, setName] = useState('');
  const [room, setRoom] = useState('');
  const [Users, setUsers] = useState([]);
  let [message, setMessage] = useState('');
  const [messages, setMessages] = useState([]);
  const [file, setFile] = useState();


  useEffect(() => {
    const { name, room } = queryString.parse(location.search);

    socket = io(ENDPOINT);

    setRoom(room);
    setName(name)
    socket.emit('join', {name, room}, (error) => {
      //console.log(name);
      if(error) {
        alert(error);
      }
    });
    socket.on('message', (message) => {
      setMessages((messages) => [...messages,  message]);
    });

    socket.on('roomData', ({room, users}) => {
      setUsers(users);
    });

    return () => {
      socket.emit('disconnect');
      socket.off();
    }
}, [location.search]);

  const sendMessage = (event) => {
    event.preventDefault();
    if(file){
      const msgObj = {
        body: file,
        type: "file",
        fileType: file.type,
        filename: file.name
      };
      setFile();
      socket.emit('sendMessage', msgObj, () => setMessage(''));

    }else{
      const msgObj = {
        body:message,
        type: "text"
      };
      socket.emit('sendMessage', msgObj, () => setMessage(''));
    }
  };

  const selectFile = (event) => {
    event.preventDefault();
    setMessage(event.target.files[0].name);
    setFile(event.target.files[0]);
  }



  return (
    <div className="outerContainer">
      <TextContainer users={Users} />
      <div className = "container">
        <InfoBar room={room}/>
        <Messages messages={messages} name={name}/>
        <Input message={message} setMessage={setMessage} sendMessage={sendMessage} selectFile={selectFile}/>
      </div>
    </div>
  );
}

export default Chat;