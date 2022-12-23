import {observer} from "mobx-react-lite";
import main from "../../../store/main";
import classes from "../style.module.css";

export default observer(function ListItem({text,id,index}){

    async function onDelete(e){
        e.preventDefault()
        await main.DeleteListItem(id,index)
    }

    return(
        <div className={classes.task}>
            <div>
                <p>{text}</p>
            </div>
            <div className={classes.actions}>
                <button onClick={onDelete}>Удалить</button>
            </div>

        </div>
    )
})