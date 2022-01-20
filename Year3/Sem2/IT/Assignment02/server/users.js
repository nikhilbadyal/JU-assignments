const users = [];
const sockets = [];
const addUser = ({id, name, room, socket}) => {
    name = name.trim().toLowerCase();
    room = room.trim().toLowerCase();

    const existingUser = users.find((user) => user.name === name && user.room === room);
    if(existingUser){
        console.log("error");
        return {error: 'existing user'};
    }

    const user = {id, name, room};
    users.push(user);
    sockets.push(socket);
    return {user};
}

const removeUser = (id) => {
    const index = users.findIndex((user)=>user.id === id);

    if(index !== -1){
        sockets.splice(index, 1);
        return users.splice(index, 1)[0];
    }
}

const getUser = (id) => users.find((user) => user.id === id);

const getUsersInRoom = (room) => users.filter((user) => user.room === room);



const getSocketByName = (name) => {
    let index = -1;//= users.findIndex((user)=>user.name === name);
    //console.log(users);
    // for(let i=0;i<sockets.length;i++){
    //     console.log(sockets[i].id);
    // }
    for(let i = 0;i<users.length;i++){
        //console.log(users[i].name + '  ' + name);
        if(users[i].name === name){
            index = i;
            break;
        }
    }

    //console.log(sockets);
    if(index !== -1){
        console.log('returning ' + sockets[index].id);
        return sockets[index];
    }else{
        console.log('returning null');
        return null;
    }
};
module.exports = {addUser, removeUser, getUser, getUsersInRoom, getSocketByName};