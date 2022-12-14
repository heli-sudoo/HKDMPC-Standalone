/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package lcmtypes;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class hkd_command_lcmt implements lcm.lcm.LCMEncodable
{
    public int N_mpcsteps;
    public double mpc_times[];
    public float hkd_controls[][];
    public float des_body_state[][];
    public int contacts[][];
    public double statusTimes[][];
    public float foot_placement[];
    public float feedback[][][];
    public float solve_time;
 
    public hkd_command_lcmt()
    {
        mpc_times = new double[10];
        hkd_controls = new float[10][24];
        des_body_state = new float[10][12];
        contacts = new int[10][4];
        statusTimes = new double[10][4];
        foot_placement = new float[12];
        feedback = new float[10][12][12];
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0xd3665dd62ca267b4L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(lcmtypes.hkd_command_lcmt.class))
            return 0L;
 
        classes.add(lcmtypes.hkd_command_lcmt.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeInt(this.N_mpcsteps); 
 
        for (int a = 0; a < 10; a++) {
            outs.writeDouble(this.mpc_times[a]); 
        }
 
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 24; b++) {
                outs.writeFloat(this.hkd_controls[a][b]); 
            }
        }
 
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 12; b++) {
                outs.writeFloat(this.des_body_state[a][b]); 
            }
        }
 
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 4; b++) {
                outs.writeInt(this.contacts[a][b]); 
            }
        }
 
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 4; b++) {
                outs.writeDouble(this.statusTimes[a][b]); 
            }
        }
 
        for (int a = 0; a < 12; a++) {
            outs.writeFloat(this.foot_placement[a]); 
        }
 
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 12; b++) {
                for (int c = 0; c < 12; c++) {
                    outs.writeFloat(this.feedback[a][b][c]); 
                }
            }
        }
 
        outs.writeFloat(this.solve_time); 
 
    }
 
    public hkd_command_lcmt(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public hkd_command_lcmt(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static lcmtypes.hkd_command_lcmt _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        lcmtypes.hkd_command_lcmt o = new lcmtypes.hkd_command_lcmt();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.N_mpcsteps = ins.readInt();
 
        this.mpc_times = new double[(int) 10];
        for (int a = 0; a < 10; a++) {
            this.mpc_times[a] = ins.readDouble();
        }
 
        this.hkd_controls = new float[(int) 10][(int) 24];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 24; b++) {
                this.hkd_controls[a][b] = ins.readFloat();
            }
        }
 
        this.des_body_state = new float[(int) 10][(int) 12];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 12; b++) {
                this.des_body_state[a][b] = ins.readFloat();
            }
        }
 
        this.contacts = new int[(int) 10][(int) 4];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 4; b++) {
                this.contacts[a][b] = ins.readInt();
            }
        }
 
        this.statusTimes = new double[(int) 10][(int) 4];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 4; b++) {
                this.statusTimes[a][b] = ins.readDouble();
            }
        }
 
        this.foot_placement = new float[(int) 12];
        for (int a = 0; a < 12; a++) {
            this.foot_placement[a] = ins.readFloat();
        }
 
        this.feedback = new float[(int) 10][(int) 12][(int) 12];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 12; b++) {
                for (int c = 0; c < 12; c++) {
                    this.feedback[a][b][c] = ins.readFloat();
                }
            }
        }
 
        this.solve_time = ins.readFloat();
 
    }
 
    public lcmtypes.hkd_command_lcmt copy()
    {
        lcmtypes.hkd_command_lcmt outobj = new lcmtypes.hkd_command_lcmt();
        outobj.N_mpcsteps = this.N_mpcsteps;
 
        outobj.mpc_times = new double[(int) 10];
        System.arraycopy(this.mpc_times, 0, outobj.mpc_times, 0, 10); 
        outobj.hkd_controls = new float[(int) 10][(int) 24];
        for (int a = 0; a < 10; a++) {
            System.arraycopy(this.hkd_controls[a], 0, outobj.hkd_controls[a], 0, 24);        }
 
        outobj.des_body_state = new float[(int) 10][(int) 12];
        for (int a = 0; a < 10; a++) {
            System.arraycopy(this.des_body_state[a], 0, outobj.des_body_state[a], 0, 12);        }
 
        outobj.contacts = new int[(int) 10][(int) 4];
        for (int a = 0; a < 10; a++) {
            System.arraycopy(this.contacts[a], 0, outobj.contacts[a], 0, 4);        }
 
        outobj.statusTimes = new double[(int) 10][(int) 4];
        for (int a = 0; a < 10; a++) {
            System.arraycopy(this.statusTimes[a], 0, outobj.statusTimes[a], 0, 4);        }
 
        outobj.foot_placement = new float[(int) 12];
        System.arraycopy(this.foot_placement, 0, outobj.foot_placement, 0, 12); 
        outobj.feedback = new float[(int) 10][(int) 12][(int) 12];
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 12; b++) {
                System.arraycopy(this.feedback[a][b], 0, outobj.feedback[a][b], 0, 12);            }
        }
 
        outobj.solve_time = this.solve_time;
 
        return outobj;
    }
 
}

