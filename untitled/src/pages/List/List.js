
import axios from 'axios';
import {useEffect, useState} from "react";

import {observer} from 'mobx-react-lite'
import main from "../../store/main";
import classes from './style.module.css'
import { Link } from "wouter"
import ListItem from "./ListItem/ListItem";

function List({id}) {

    useEffect(()=>{
        main.getListData(id)
    },[])


    const [state,setState] = useState('')

    function changeHandler(e){
        setState(e.target.value)
    }

    async function onSubmit(e){
        e.preventDefault()
        await main.sendTask(state,id)
        setState('')
    }

    return (
        <div className={classes.App}>

            <header>
                <h1>Список задач</h1>
                <form onSubmit={onSubmit}>
                    <input type="text" value={state} onChange={changeHandler} className={classes.newTaskInput} placeholder="Какие у тебя планы?"/>
                    <button type="submit"  className={classes.newTaskSubmit}>Добавить в план</button>
                </form>
            </header>
            <main>
                <section className={classes.taskList}>
                    <h2 className={main.currentList.length === 0 && classes.hidden }>Планы</h2>
                    <div className={classes.tasks}>
                        {main.currentList.length > 0 ? main.currentList.map((item,index)=><ListItem id={id} index={index} text={item}/>):<p className={classes.noPlans}>Пока нет планов</p>}
                    </div>
                </section>
            </main>

        </div>
    );
}



export default observer(List);