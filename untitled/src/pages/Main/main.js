import './App.module.css';
import axios from 'axios';
import {useEffect, useState} from "react";

import {observer} from 'mobx-react-lite'
import main from "../../store/main";

import { Link } from "wouter"
import "./projectv2.css"
function Main() {

    useEffect(()=>{
        main.getData()
    },[])

    return (
        <>

            <h1 style={{textAlign:"center"}}>Заметчик</h1>
            <div className="fl">

                <div className="row">
                    <div className="dni"> ПН</div>
                    <div className="dni"> ВТ</div>
                    <div className="dni"> СР</div>
                    <div className="dni"> ЧТ</div>
                    <div className="dni"> ПТ</div>
                    <div className="dni"> СБ</div>
                    <div className="dni"> ВС</div>
                </div>

                <div className="row">
                    <div className="an item">28</div>
                    <div className="an item">29</div>
                    <div className="an item">30</div>
                    {main.data.slice(0,4).map((_,index)=><Link href={`/${index}`}><div>{index+1}</div></Link>)}
                </div>

                <div className="row">
                    {main.data.slice(4,11).map((_,index)=><Link href={`/${index}`}><div>{index+5}</div></Link>)}
                </div>
                <div className="row">
                    {main.data.slice(11,18).map((_,index)=><Link href={`/${index}`}><div>{index+1+11}</div></Link>)}
                </div>
                <div className="row">
                    {main.data.slice(18,25).map((_,index)=><Link href={`/${index}`}><div>{index+1+18}</div></Link>)}
                </div>
                <div className="row">
                    {main.data.slice(25,31).map((_,index)=><Link href={`/${index}`}><div>{index+1+25}</div></Link>)}
                    <div className="vih an">1</div>
                </div>
            </div>


        </>
    );
}

export default observer(Main);
