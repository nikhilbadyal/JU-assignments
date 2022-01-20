import React from 'react';

import './TextContainer.css';
import {makeStyles} from "@material-ui/core/styles";

const useStyles = makeStyles((theme) => ({

    avatar: {
        verticalAlign: "middle",
        width: "30px",
        height: "30px",
        borderRadius: "50%",
    },
}));

// eslint-disable-next-line react/prop-types
function TextContainer({users}) {
    const classes = useStyles();
    return <div className="textContainer">
        {
            users
                ? (
                    <div>
                        <h1>Current Users:</h1>
                        <div className="activeContainer">
                            <h2>
                                {users.map(({name}) => (
                                    <div key={name} className="activeItem">
                                        {name}
                                        <img alt="Online Icon" className={classes.avatar} src='https://source.unsplash.com/random'/>
                                    </div>
                                ))}
                            </h2>
                        </div>
                    </div>
                )
                : null
        }
    </div>;
}

export default TextContainer;