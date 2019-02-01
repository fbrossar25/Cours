import { Component, OnInit, Input } from '@angular/core';
import { Coin} from '../model/Coin'

@Component({
  selector: 'app-crypto',
  templateUrl: './crypto.component.html',
  styleUrls: ['./crypto.component.css']
})
export class CryptoComponent implements OnInit {

  @Input () coin : Coin;
  constructor() { }

  ngOnInit() {
  }

  getColor(){
    return "red";
  }
}
