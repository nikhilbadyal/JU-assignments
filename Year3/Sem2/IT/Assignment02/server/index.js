const express = require('express');
const socketIo = require('socket.io');
const http = require('http');
const {addUser, removeUser, getUser, getUsersInRoom, getSocketByName} = require('./users.js');
const port = (Number)(process.env.port || 5000);
const CryptoJS = require('crypto-js');
const router = require('./router');

const app = express();
const server = http.createServer(app);
const io = socketIo(server, { wsEngine: 'ws'});

app.use(router);

io.on('connection', (socket) => {

    console.log('We have a new connection!!!!');

    socket.on('join', ({name, room}, callback) => {
        console.log(name + ' ' + socket.id);
        const {error, user} = addUser({id:socket.id, name, room, socket});

        if(error) return callback(error);
        let msg = `${user.name}, Welcome to the room ${user.room}`;
        let msg2 =  `${user.name} has joined`;

        socket.emit('message', {user: 'admin', body: msg  });
        socket.broadcast.to(user.room).emit('message', {user: 'admin', body:msg2});
        socket.join(user.room);
        io.to(user.room).emit('roomData', {room: user.room, users: getUsersInRoom(user.room) });
        callback();
    });

    const encryptWithAES = text => {
        const passphrase = '123';
        return CryptoJS.AES.encrypt(text, passphrase).toString();
    };

    const decryptWithAES = ciphertext => {
        const passphrase = '123';
        const bytes = CryptoJS.AES.decrypt(ciphertext, passphrase);
        const originalText = bytes.toString(CryptoJS.enc.Utf8);
        return originalText;
    };

    decryptWithAES("wrrgwrg");
    encryptWithAES("ergerg");
    socket.on('sendMessage', (data, callback) => {
        if(data.type === "file"){
            const user = getUser(socket.id);
            io.to(user.room).emit('message', {user: user.name, body: data.body, type: "file", fileType: data.fileType, filename: data.filename});
            callback();
        }else{
            let message = data.body;
            let receiverName = "";
            let extractedMessage = "";
            let single = false;
            let receiverNameArray = [];
            if(message[0] === '@'){
                single = true;
                let i=0;
                while(i < message.length && message[i] === '@'){
                    i++;
                    receiverName = "";
                    while(i < message.length && message[i] !== ' '){
                        receiverName = receiverName + message[i];
                        i++;
                    }
                    while(i < message.length && message[i] === ' '){
                        i++;
                    }
                    receiverNameArray.push(receiverName);
                }
                extractedMessage = message.substring(i, message.length);
            }
            if(single){
                for(let i=0;i<receiverNameArray.length;i++){
                    let userReceiver = getSocketByName(receiverNameArray[i]);
                    if(userReceiver !== null){
                        userReceiver.emit('message', {user: getUser(socket.id).name, body: extractedMessage});
                    }
                }
                const userSender = getUser(socket.id);
                socket.emit('message', {user: userSender.name, body: message})
                callback();
            }else{
                const user = getUser(socket.id);
                io.to(user.room).emit('message', {user: user.name, body: message});
                callback();
            }
        }

    });

    socket.on('disconnect', () => {
        console.log("user have left!!!!");
        const user = removeUser(socket.id);
        if(user){
            io.to(user.room).emit('message', {user: 'admin', body: `${user.name} has left.`});
            io.to(user.room).emit('roomData', {room: user.room, users:getUsersInRoom(user.room)});
        }
    })
});

server.listen(port, () => console.log(`Server has Started on port ${port}`));

